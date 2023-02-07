#pragma once
#include "CoreMinimal.h"
#include "FXUpdate.h"
#include "EMultiFXUse.h"
#include "FXUpdate_InitialMatchTimeDilation.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_InitialMatchTimeDilation : public UFXUpdate {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiFXUse UseTimeDilation;
    
public:
    UFXUpdate_InitialMatchTimeDilation();
};

