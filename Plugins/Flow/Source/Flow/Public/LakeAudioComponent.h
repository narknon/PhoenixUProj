#pragma once
#include "CoreMinimal.h"
#include "AkComponent.h"
#include "LakeAudioSamplePoint.h"
#include "LakeAudioComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class FLOW_API ULakeAudioComponent : public UAkComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxNumAudioPoints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PointSpacing;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLakeAudioSamplePoint> SamplePoints;
    
public:
    ULakeAudioComponent();
};

