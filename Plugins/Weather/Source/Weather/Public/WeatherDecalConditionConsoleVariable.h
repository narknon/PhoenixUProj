#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalSimpleCondition.h"
#include "WeatherDecalConditionConsoleVariable.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWeatherDecalConditionConsoleVariable : public UWeatherDecalSimpleCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ConsoleVariableName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCreateIfNotFound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEditorOnly;
    
    UWeatherDecalConditionConsoleVariable();
};

