#pragma once
#include "CoreMinimal.h"
#include "BoolProvider.h"
#include "Bool_FallbackChain.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UBool_FallbackChain : public UBoolProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UBoolProvider*> Entries;
    
    UBool_FallbackChain();
};

