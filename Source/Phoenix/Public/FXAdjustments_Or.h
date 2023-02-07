#pragma once
#include "CoreMinimal.h"
#include "FXAdjustments.h"
#include "FXAdjustments_Or.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAdjustments_Or : public UFXAdjustments {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXAdjustments*> Adjustments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFailIfNotFound;
    
public:
    UFXAdjustments_Or();
};

