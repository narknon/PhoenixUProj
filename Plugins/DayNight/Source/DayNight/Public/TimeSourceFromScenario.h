#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TimeSourceLocal.h"
#include "TimeSourceFromScenario.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UTimeSourceFromScenario : public UTimeSourceLocal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle Scenario;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Rate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseRate;
    
    UTimeSourceFromScenario();
    UFUNCTION(BlueprintCallable)
    void EditorForceUpdate();
    
};

