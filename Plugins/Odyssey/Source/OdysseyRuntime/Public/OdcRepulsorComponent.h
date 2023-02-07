#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "OdcRepulsorComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ODYSSEYRUNTIME_API UOdcRepulsorComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RepulsorRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RepulsorOuterCushion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RepulsorInnerCushion;
    
    UOdcRepulsorComponent();
};

