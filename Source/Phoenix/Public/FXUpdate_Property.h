#pragma once
#include "CoreMinimal.h"
#include "EMultiFXUse.h"
#include "FXUpdate_Tick.h"
#include "FXUpdate_Property.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXUpdate_Property : public UFXUpdate_Tick {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiFXUse PropertySource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SourcePropertyName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TargetPropertyName;
    
public:
    UFXUpdate_Property();
};

