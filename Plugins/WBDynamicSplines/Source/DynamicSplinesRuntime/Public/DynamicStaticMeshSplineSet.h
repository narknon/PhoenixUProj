#pragma once
#include "CoreMinimal.h"
#include "DynamicSplineSet.h"
#include "DynamicStaticMeshSplineSet.generated.h"

class UStaticMesh;

UCLASS(Blueprintable)
class DYNAMICSPLINESRUNTIME_API UDynamicStaticMeshSplineSet : public UDynamicSplineSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* ReferenceMesh;
    
    UDynamicStaticMeshSplineSet();
};

