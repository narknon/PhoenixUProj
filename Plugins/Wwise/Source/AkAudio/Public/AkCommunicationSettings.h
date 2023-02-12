#pragma once
#include "CoreMinimal.h"
#include "AkCommunicationSettings.generated.h"

USTRUCT(BlueprintType)
struct FAkCommunicationSettings {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 PoolSize;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint16 DiscoveryBroadcastPort;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint16 CommandPort;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint16 NotificationPort;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString NetworkName;
    
    AKAUDIO_API FAkCommunicationSettings();
};

