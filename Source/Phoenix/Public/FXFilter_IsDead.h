#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "FXFilter_IsDead.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_IsDead : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ConsiderTakeAKneeDead;
    
public:
    UFXFilter_IsDead();
};

