#include "PhxAnimationSharingManager.h"
#include "Templates/SubclassOf.h"

class UPhxAnimationSharingManager;
class UPhxAnimationSharingSetup;
class UWorld;

UPhxAnimationSharingManager* UPhxAnimationSharingManager::GetPhxAnimationSharingManager(UWorld* InWorld, TSubclassOf<UPhxAnimationSharingSetup> InClass) {
    return NULL;
}

UPhxAnimationSharingManager::UPhxAnimationSharingManager() {
}

