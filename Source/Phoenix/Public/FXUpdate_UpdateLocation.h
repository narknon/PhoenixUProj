#pragma once
#include "CoreMinimal.h"
#include "FXUpdate_Tick.h"
#include "FXUpdate_UpdateLocation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_UpdateLocation : public UFXUpdate_Tick {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdateXY;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUpdateZ;
    
public:
    UFXUpdate_UpdateLocation();
};

