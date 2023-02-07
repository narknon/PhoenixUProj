#pragma once
#include "CoreMinimal.h"
#include "IntProvider.h"
#include "Int_FallbackChain.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UInt_FallbackChain : public UIntProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UIntProvider*> Entries;
    
    UInt_FallbackChain();
};

