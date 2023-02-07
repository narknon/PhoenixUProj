#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AblCollisionShape.h"
#include "AblCollisionShapeBox.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblCollisionShapeBox : public UAblCollisionShape {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector m_HalfExtents;
    
public:
    UAblCollisionShapeBox();
};

