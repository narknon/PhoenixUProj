#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MapResponse.generated.h"

UCLASS(Blueprintable)
class UMapResponse : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Handled;
    
    UMapResponse();
};

