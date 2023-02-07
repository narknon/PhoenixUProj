#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OrientToComponent.h"
#include "OrientToSlerp.h"
#include "OrientToAbsoluteComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UOrientToAbsoluteComponent : public UOrientToComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator WorldRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOrientToSlerp Smoothing;
    
    UOrientToAbsoluteComponent();
};

