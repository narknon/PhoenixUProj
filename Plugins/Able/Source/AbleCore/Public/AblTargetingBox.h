#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AblTargetingBase.h"
#include "AblTargetingBox.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblTargetingBox : public UAblTargetingBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector m_HalfExtents;
    
public:
    UAblTargetingBox();
};

