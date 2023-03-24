#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "DialogueConversationReference.h"
#include "PhoenixBudgetedActor.h"
#include "Templates/SubclassOf.h"
#include "SimpleInteractObject.generated.h"

class AActor;
class UCognitionStimuliSourceComponent;
class URootMotionModProperties_Interact;

UCLASS(Blueprintable)
class ASimpleInteractObject : public APhoenixBudgetedActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CognitionStimuliSource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UClass* AbilityClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPartialBody;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> AbilitySpawnActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AbilitySpawnOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator AbilitySpawnRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URootMotionModProperties_Interact* InteractProperties;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayDialogueAfterInteractTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueConversationReference DialogueEventName;
    
    ASimpleInteractObject(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void PlayDialogue();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void InteractionInitiated();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UClass* GetAbilityClass();
    
};

