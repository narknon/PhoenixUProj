#pragma once
#include "CoreMinimal.h"
#include "BaseArchitectAsset.h"
#include "ObjectArchitectAsset_Connection.h"
#include "ObjectArchitectAsset.generated.h"

UCLASS(Blueprintable)
class ANIMATIONARCHITECTRUNTIME_API UObjectArchitectAsset : public UBaseArchitectAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FObjectArchitectAsset_Connection> ConnectionArray;
    
    UObjectArchitectAsset();
};

