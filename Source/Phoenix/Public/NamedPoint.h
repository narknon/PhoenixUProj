#pragma once
#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "EVolumeType.h"
#include "NamedPoint.generated.h"

class UPrimitiveComponent;

UCLASS(Blueprintable)
class ANamedPoint : public ATargetPoint {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString m_nameOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool m_bAppendLevelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EVolumeType VolumeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* Volume;
    
public:
    ANamedPoint(const FObjectInitializer& ObjectInitializer);
};

