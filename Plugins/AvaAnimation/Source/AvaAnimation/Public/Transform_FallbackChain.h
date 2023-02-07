#pragma once
#include "CoreMinimal.h"
#include "TransformProvider.h"
#include "Transform_FallbackChain.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UTransform_FallbackChain : public UTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTransformProvider*> Entries;
    
    UTransform_FallbackChain();
};

