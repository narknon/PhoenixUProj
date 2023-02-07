#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HandleLinkInfo.generated.h"

class UHandleLink;

UCLASS(Blueprintable)
class UTILITIESRUNTIME_API UHandleLinkInfo : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint32, UHandleLink*> m_handleToLinkMap;
    
    UHandleLinkInfo();
};

