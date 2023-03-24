#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Templates/SubclassOf.h"
#include "WorldObject.h"
#include "WorldInteractObject.generated.h"

class AActor;
class UCognitionStimuliSourceComponent;
class URootMotionModProperties_Interact;

UCLASS(Blueprintable)
class AWorldInteractObject : public AWorldObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CognitionStimuliSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* AbilityClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> AbilitySpawnActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AbilitySpawnOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator AbilitySpawnRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URootMotionModProperties_Interact* InteractProperties;
    
    AWorldInteractObject(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InteractionInitiated();
    
};

