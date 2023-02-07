#pragma once
#include "CoreMinimal.h"
#include "Screen.h"
#include "BroomChallengeScreen.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class PHOENIX_API UBroomChallengeScreen : public UScreen {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RaceId;
    
public:
    UBroomChallengeScreen();
};

