#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "BaseArchitectMonolithicAsset_Class.h"
#include "BaseArchitectMonolithicAsset_DefaultKeyOrder.h"
#include "BaseArchitectMonolithicAsset.generated.h"

UCLASS(Abstract, Blueprintable)
class UBaseArchitectMonolithicAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FBaseArchitectMonolithicAsset_Class> ClassMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FBaseArchitectMonolithicAsset_DefaultKeyOrder> DefaultKeyOrderMap;
    
    UBaseArchitectMonolithicAsset();
};

