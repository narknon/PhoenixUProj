#pragma once
#include "CoreMinimal.h"
#include "EWindParametersTimeBase.h"
#include "SceneAction_WeatherSequence.h"
#include "WindDefinitionName.h"
#include "SceneAction_WeatherSequenceWindMulti.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WEATHER_API USceneAction_WeatherSequenceWindMulti : public USceneAction_WeatherSequence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWindParametersTimeBase BlendInTimeBase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FWindDefinitionName> Definitions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRandomizeOrder;
    
    USceneAction_WeatherSequenceWindMulti();
};

