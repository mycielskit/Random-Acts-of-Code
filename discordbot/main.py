import discord

token = open("token.txt", "r").read()

client = discord.Client()
Author = 'X'
F = 'X'


@client.event  # event decorator/wrapper
async def on_ready():
    activity = discord.Activity(name='for 1000 members!', type=discord.ActivityType.watching)
    await client.change_presence(activity=activity, status=discord.Status.idle)
    print(f"Beep, boop. Logged in as {client.user}")


@client.event
async def on_message(msg):
    if msg.author.bot or msg.content[0] != '$':
        if msg.author.bot:
            server = client.get_guild(X)
            if len(server.members) == 1004:
                botcommands = client.get_channel(X)
                await botcommands.send(f'{Author} {F}')
                await botcommands.send(f'We\'ve reached 1000 members! :tada:')
                await client.change_presence(status=discord.Status.invisible)
                await client.close()
        return
    print(f'{msg.channel}: {msg.author}: {msg.author.name}: {msg.content}')
    cmd = msg.content[1:]
    if cmd == "exit":
        botcommands = client.get_channel(X)
        await botcommands.send(f'{Author}')
        await botcommands.send('Going offline. See ya!')
        await client.change_presence(status=discord.Status.invisible)
        await client.close()
        return
    elif cmd == "test":
        await msg.channel.send(f'{Author}')
        server = client.get_guild(X)
        botcommands = client.get_channel(X)
        await botcommands.send(len(server.members))
        return


if __name__ == '__main__':
    secret = ''
    client.run(token)
