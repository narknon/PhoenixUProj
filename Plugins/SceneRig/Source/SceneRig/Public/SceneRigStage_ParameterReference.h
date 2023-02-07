#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterReference.generated.h"

class UStruct;

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigStage_ParameterReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStruct* ParameterType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ReferenceName;
    
    FSceneRigStage_ParameterReference();
};
FORCEINLINE uint32 GetTypeHash(const FSceneRigStage_ParameterReference) { return 0; }

