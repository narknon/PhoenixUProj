#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AblCollisionSweepShape.h"
#include "AblCollisionSweepBox.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblCollisionSweepBox : public UAblCollisionSweepShape {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector m_HalfExtents;
    
public:
    UAblCollisionSweepBox();
};

