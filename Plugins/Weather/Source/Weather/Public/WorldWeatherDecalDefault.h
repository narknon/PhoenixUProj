#pragma once
#include "CoreMinimal.h"
#include "WeatherDecalSetup.h"
#include "WorldWeatherDecal.h"
#include "WorldWeatherDecalDefault.generated.h"

class UWeatherDecalCondition;
class UWeatherDecalSettings;
class UWeatherDecalUpdate;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API UWorldWeatherDecalDefault : public UWorldWeatherDecal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWeatherDecalSetup Setup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWeatherDecalSettings*> InitialSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWeatherDecalCondition*> ShowConditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWeatherDecalUpdate*> Updates;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendThreshold;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEditorOnly;
    
    UWorldWeatherDecalDefault();
};

