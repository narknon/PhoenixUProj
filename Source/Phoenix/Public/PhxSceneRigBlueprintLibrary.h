#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CharacterNameAndIsLocalPlayer.h"
#include "DialogueLineAndAudioFlags.h"
#include "PhxSceneRigBlueprintLibrary.generated.h"

class ASceneRigActor;
class UObject;
class USceneActionState_ClothOptions;
class USceneRig;

UCLASS(Blueprintable)
class UPhxSceneRigBlueprintLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UPhxSceneRigBlueprintLibrary();
    UFUNCTION(BlueprintCallable)
    static USceneActionState_ClothOptions* FindFirstSceneActionClothingOptionState(ASceneRigActor* InSceneRigActor);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FDialogueLineAndAudioFlags> FindDialogueEventReferences(USceneRig* SceneRig);
    
    UFUNCTION(BlueprintCallable)
    static TSet<FCharacterNameAndIsLocalPlayer> FindCharacterReferencesInObject(UObject* InObject);
    
};

