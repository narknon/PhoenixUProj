#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SceneAction_WeatherSequenceEnvGlobalColor.h"
#include "SceneAction_WeatherSequenceEnvGlobalColorConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceEnvGlobalColorConstant : public USceneAction_WeatherSequenceEnvGlobalColor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Value;
    
    USceneAction_WeatherSequenceEnvGlobalColorConstant();
};

