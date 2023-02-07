#pragma once
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "OdcObstacleMeshComponent.generated.h"

class UStaticMesh;

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ODYSSEYRUNTIME_API UOdcObstacleMeshComponent : public UStaticMeshComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* NavStaticMesh;
    
    UOdcObstacleMeshComponent();
};

