## A little tutorial
***This assumes you have read the platinmods tutorial.***
This tutorial uses Pg3d as an example.
### How to access other classes 
This is also a very convenient method when update() is not available. It can also be used to reduce code. <a href="https://github.com/jbro129/Universal-Unity-NoClip" target="_blank">I got the idea from Jbro129's noclip</a>
Thank you.

### How to reflect only on yourself
I did an Immortality hook before, but my screen reflected it to all players. Here is how to deal with it. This works for other functions as well.
I was initially unsure where my player id was stored. But by using ghidra I now know where it is managed:) According to Ghidra, it was managed in photonview in Player_move_c.
```c#
public PhotonView photonView; // 0x3D0
```
Let's hook this up. It is int type because it manages the Player id. In other words, the code is as follows
```cpp
int PhotonView = *(int*)((uint64_t)instance + 0x3D0);
// player id
LOGD("Player ID: %d", PhotonView);
```
This allowed me to get my id!  
Next, we will explain how to apply it only to yourself.
You can use get_isMine and apply it only to yourself. 
```c#
// RVA: 0x49B4078 Offset: 0x49B4078 VA: 0x49B4078
internal bool 丆丟不丙丅与上丗与() { }
```
No parameters are shown in dump.cs, but ghidra shows an int type for the parameter. In other words, put the player id of photonview here. * but you can also do it with get_ismine in photonview. Since PhotonView$$get_isMine is available, we thought we could substitute it.  
If you have ever created a bot such as Discord, you know that you always need a destination (id) and other information when sending messages and so on. It is a little different in the game, but it is similar.  
The overall code is as follows
```cpp
int myid = *(int*)((uint64_t)instance + 0x3D0);
if (IIsMine(instance, (int)myid)) {
    if (isGod2) {
        setisImmortality(instance, true);
        LOGD("Photon View Player: %d", myid);
    }
```
This will grant Immortality only to you, not reflected to everyone! Congratulations! 
### How to reflect this to everyone
This method simply uses logical inversion. Use the SetBigHeadEffect(?) here.
When you use logical inversion, you are specifying a user other than yourself. You will have to find out for yourself how logical inversion really works. You'll have to look up the meaning of logical inversion yourself. Logical inversion just uses ! is all you need to do.  
The overall code is as follows
```cpp
int myid = *(int*)((uint64_t)instance + 0x3D0);
if (!IIsMine(instance, (int)myid)) {
    if (isBigHead) {
        SetBigHeadEffect(instance, true);
    }
```
Usually if you use only setbighead nothing happens. However, if you put in someone else's id it actually works.    

Thanks for reading this far.  
If you have any questions, please contact us at discord: Unknown-19#6775
