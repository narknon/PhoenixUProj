#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SceneRigBPUtilities.generated.h"

class AActor;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigBPUtilities : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    USceneRigBPUtilities();
    UFUNCTION(BlueprintCallable)
    static void AddRegisteredActor(AActor* Actor, FName RegisteredActorName);
    
};

