#pragma once
#include "CoreMinimal.h"
#include "DateTimeInput.h"
#include "TimeSourceLocal.h"
#include "TimeSourceFromDateTime.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API UTimeSourceFromDateTime : public UTimeSourceLocal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDateTimeInput DateTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Rate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseRate;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnabled;
    
    UTimeSourceFromDateTime();
    UFUNCTION(BlueprintCallable)
    void EditorForceUpdate();
    
};

