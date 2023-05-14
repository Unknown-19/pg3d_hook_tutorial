// This is the source decompiled by ghidra.

undefined Player_move_c$$get_isMine(int param_1)

{
  byte bVar1;
  int iVar2;
  
  if (DAT_0439a891 == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_005abd7c(0xa74c);
  }
  if (*(char *)(param_1 + 0x2b4) == '\0') {
    if (((*(byte *)(UnityEngine.Object_TypeInfo + 0xbf) & 2) != 0) &&
       (*(int *)(UnityEngine.Object_TypeInfo + 0x70) == 0)) {
                    /* WARNING: Subroutine does not return */
      FUN_005ba778();
    }
    iVar2 = UnityEngine.Object$$op_Equality(*(undefined4 *)(param_1 + 0x1d0),0,0);
    if (iVar2 == 1) {
      if (((*(byte *)(UnityEngine.Debug_TypeInfo + 0xbf) & 2) != 0) &&
         (*(int *)(UnityEngine.Debug_TypeInfo + 0x70) == 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_005ba778();
      }
      UnityEngine.Debug$$Log(StringLiteral_27167,0);
    }
    else {
      if (*(int *)(param_1 + 0x1d0) == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_005d89e0(0);
      }
      bVar1 = 0;
      iVar2 = PhotonView$$get_isMine(*(int *)(param_1 + 0x1d0),0);
      if (iVar2 == 1) {
        bVar1 = Player_move_c$$get_isAI(param_1);
        bVar1 = bVar1 ^ 1;
      }
      *(undefined *)(param_1 + 0x2b4) = 1;
      *(byte *)(param_1 + 0x2b3) = bVar1;
    }
  }
  return *(undefined *)(param_1 + 0x2b3);
}
