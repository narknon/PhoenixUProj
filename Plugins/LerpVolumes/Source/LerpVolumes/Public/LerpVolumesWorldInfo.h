#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesWorldInfo.generated.h"

class ALerpVolumesSingleton;
class ULerpVolumesLocalEvaluationComponent;
class UObject;

USTRUCT(BlueprintType)
struct FLerpVolumesWorldInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ALerpVolumesSingleton* Singleton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<ULerpVolumesLocalEvaluationComponent*> LocalEvaluators;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UObject>> Volumes;
    
    LERPVOLUMES_API FLerpVolumesWorldInfo();
};

