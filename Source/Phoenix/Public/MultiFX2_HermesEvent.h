#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_Filtered.h"
#include "MultiFX2_HermesEvent.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_HermesEvent : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString HermesMessage;
    
public:
    UMultiFX2_HermesEvent();
};

