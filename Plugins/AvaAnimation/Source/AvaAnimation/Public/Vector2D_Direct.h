#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Vector2DProvider.h"
#include "Vector2D_Direct.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UVector2D_Direct : public UVector2DProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D Value;
    
    UVector2D_Direct();
};

