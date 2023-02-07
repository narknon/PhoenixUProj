#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VectorProvider.h"
#include "Vector_Direct.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UVector_Direct : public UVectorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Value;
    
    UVector_Direct();
};

