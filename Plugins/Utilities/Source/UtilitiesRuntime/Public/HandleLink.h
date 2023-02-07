#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HandleLink.generated.h"

UCLASS(Blueprintable)
class UTILITIESRUNTIME_API UHandleLink : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* m_pObject;
    
    UHandleLink();
};

