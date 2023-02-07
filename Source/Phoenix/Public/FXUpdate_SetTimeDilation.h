#pragma once
#include "CoreMinimal.h"
#include "FXUpdate.h"
#include "FXUpdate_SetTimeDilation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_SetTimeDilation : public UFXUpdate {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeDilation;
    
public:
    UFXUpdate_SetTimeDilation();
};

