#include "PhxSceneRigBlueprintLibrary.h"

class ASceneRigActor;
class UObject;
class USceneActionState_ClothOptions;
class USceneRig;

USceneActionState_ClothOptions* UPhxSceneRigBlueprintLibrary::FindFirstSceneActionClothingOptionState(ASceneRigActor* InSceneRigActor) {
    return NULL;
}

TArray<FDialogueLineAndAudioFlags> UPhxSceneRigBlueprintLibrary::FindDialogueEventReferences(USceneRig* SceneRig) {
    return TArray<FDialogueLineAndAudioFlags>();
}

TSet<FCharacterNameAndIsLocalPlayer> UPhxSceneRigBlueprintLibrary::FindCharacterReferencesInObject(UObject* InObject) {
    return TSet<FCharacterNameAndIsLocalPlayer>();
}

UPhxSceneRigBlueprintLibrary::UPhxSceneRigBlueprintLibrary() {
}

