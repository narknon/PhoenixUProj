#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TransformProvider.h"
#include "Transform_Tagged.generated.h"

class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UTransform_Tagged : public UTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
    UTransform_Tagged();
};

