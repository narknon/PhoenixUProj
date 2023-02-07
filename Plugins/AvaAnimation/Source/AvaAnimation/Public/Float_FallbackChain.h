#pragma once
#include "CoreMinimal.h"
#include "FloatProvider.h"
#include "Float_FallbackChain.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UFloat_FallbackChain : public UFloatProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFloatProvider*> Entries;
    
    UFloat_FallbackChain();
};

