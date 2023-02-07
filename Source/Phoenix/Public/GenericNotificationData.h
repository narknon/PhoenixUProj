#pragma once
#include "CoreMinimal.h"
#include "GenericNotificationData.generated.h"

USTRUCT(BlueprintType)
struct FGenericNotificationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString HeaderText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SubheaderText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString IconName;
    
    PHOENIX_API FGenericNotificationData();
};

