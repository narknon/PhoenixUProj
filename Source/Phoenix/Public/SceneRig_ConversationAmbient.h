#pragma once
#include "CoreMinimal.h"
#include "PreviewVariableRequest.h"
#include "GameplayTagContainer.h"
#include "SceneRigProvider.h"
#include "SceneRig_ConversationAmbient.generated.h"

class UAnimationArchitectTagProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API USceneRig_ConversationAmbient : public USceneRigProvider, public IPreviewVariableRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer Tags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAnimationArchitectTagProvider*> TagProviders;
    
    USceneRig_ConversationAmbient();
    
    // Fix for true pure virtual functions not being implemented
};

