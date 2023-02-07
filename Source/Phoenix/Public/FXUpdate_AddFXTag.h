#pragma once
#include "CoreMinimal.h"
#include "FXUpdate.h"
#include "FXUpdate_AddFXTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_AddFXTag : public UFXUpdate {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Tag;
    
public:
    UFXUpdate_AddFXTag();
};

