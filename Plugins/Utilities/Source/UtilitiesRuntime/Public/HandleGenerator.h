#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HandleGenerator.generated.h"

class UHandleLinkInfo;

UCLASS(Blueprintable)
class UTILITIESRUNTIME_API UHandleGenerator : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint32, UHandleLinkInfo*> m_linkInfoMap;
    
public:
    UHandleGenerator();
};

