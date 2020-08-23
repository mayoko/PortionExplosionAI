export enum MarbleColor {
    RED = 'RED',
    BLUE = 'BLUE',
    YELLOW = 'YELLOW',
    BLACK = 'BLACK',
    NONE = 'NONE',
}

export const stringToMarbleColor = (colorString: string): MarbleColor => {
    const matchedMarbleColor = Object.values(MarbleColor).filter(
        value => value === colorString,
    );

    return matchedMarbleColor.length > 0
        ? matchedMarbleColor[0]
        : MarbleColor.NONE;
};
