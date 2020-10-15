modded class ActionDismantlePart {
    protected bool DismantleCondition(PlayerBase player, ActionTarget target, ItemBase item, bool camera_check) {
        Fence fence = Fence.Cast(target.GetObject());

        if (fence) {
            if (GetDayZGame().GetCodeLockConfig().OwnerOnlyDismantle()) {
                CodeLock codelock = CodeLock.Cast(fence.GetCodeLock());

                if (codelock) {
                    bool isOwner = codelock.IsOwner(player.GetIdentity().GetId());

                    if (!isOwner) {
                        return false;
                    }
                }
            }
        }
        return super.DismantleCondition(player, target, item, camera_check);
    }
}