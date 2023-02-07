#pragma once
#include "CoreMinimal.h"
#include "EAccountLinkStatus.generated.h"

UENUM(BlueprintType)
enum class EAccountLinkStatus : uint8 {
    NoOnlineConnection,
    LocalOnlyProfile,
    NoLink,
    WBPNLoggedIn,
    WBPNCompleted,
    WWIDLinked,
};

