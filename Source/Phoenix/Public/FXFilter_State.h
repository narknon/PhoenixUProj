#pragma once
#include "CoreMinimal.h"
#include "FXFilter.h"
#include "EMultiFXState.h"
#include "FXFilter_State.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_State : public UFXFilter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiFXState State;
    
public:
    UFXFilter_State();
};

