#pragma once
#include "CoreMinimal.h"
#include "NameProvider.h"
#include "Name_FallbackChain.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UName_FallbackChain : public UNameProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UNameProvider*> Entries;
    
    UName_FallbackChain();
};

