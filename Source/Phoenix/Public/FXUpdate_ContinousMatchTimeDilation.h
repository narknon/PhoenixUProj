#pragma once
#include "CoreMinimal.h"
#include "EMultiFXUse.h"
#include "FXUpdate_Tick.h"
#include "FXUpdate_ContinousMatchTimeDilation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_ContinousMatchTimeDilation : public UFXUpdate_Tick {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiFXUse UseTimeDilation;
    
public:
    UFXUpdate_ContinousMatchTimeDilation();
};

